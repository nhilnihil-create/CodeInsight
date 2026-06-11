#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

bool check(int cx,int cy,int H,vector<int> x,vector<int> y,vector<int> h){
    int ch;
    bool flag = false;
    rep(i,x.size()){
        ch = max(H-abs(x[i]-cx)-abs(y[i]-cy),0);
        if(ch != h[i]){

        }
    }
}

int main(void)
{
    int N,cx,cy,H,ch,n;
    bool flag = true;

    cin >> N;
    vector<int> x(N),y(N),h(N);

    rep(i, N){
        cin >> x[i] >> y[i] >> h[i];
    }

    n = 0;

    //h[i] = 0だとHが求められない。0以外が出てくるまでループ
    rep(i,N){
        if(h[i] > 0){
            n = i;
            break;
        }
    }

    rep(cx,101){
        rep(cy,101){
            flag = true;
            H = h[n]+abs(x[n]-cx)+abs(y[n]-cy);
            rep(i,N){
                if(h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy),0)){
                    flag = false;
                    break;
                }
            }
            if(flag){//制約よい一つのピラミッドしか存在しない
                cout << cx << " " << cy << " " << H << endl;
            }
        }

    }
    

    return 0;
}