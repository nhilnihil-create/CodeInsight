#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
typedef long long ll;
const int INF = 1e+9+7;
using ipair= pair<int,int>;
bool operator>(const ipair a,const ipair b){return a.first > b.first;};

int main(){
    int N;
    cin >> N;
    vector<int> x(N),y(N),h(N);
    int h_max=0;
    int i_h_max;
    rep(i,N){
        cin >> x[i] >> y[i] >> h[i];
        if(h[i]>h_max){
            h_max=h[i];
            i_h_max=i;
        }
    }

    int ans_x,ans_y,ans_h,H,cnt;
    rep(cx,101){
        rep(cy,101){
            cnt=0;
            H=h[i_h_max]+abs(x[i_h_max]-cx)+abs(y[i_h_max]-cy);
            rep(i,N){
                if(h[i]!=max(0,H-abs(x[i]-cx)-abs(y[i]-cy))) break;
                cnt++;
            }
            if(cnt==N){
                ans_x=cx;
                ans_y=cy;
                ans_h=H;
            }
        }
    }
    cout << ans_x << " " << ans_y << " " << ans_h << endl;
}
