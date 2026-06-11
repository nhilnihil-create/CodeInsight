#include<iostream>
#include<vector>
#include<algorithm>
#define BIT(n) (1<<(n))
using namespace std;

int count(int x){
    for(int i=21;;--i){
        if(BIT(i)&x)return i;
    }
}

vector<int> make(int a, int b, int c){
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    return res;
}
int main(){
    int L;
    cin >> L;
    vector<vector<int> > ans;
    int r = count(L);
    int N = r + 1;
    int M = r * 2;
    for(int i=1;i<N;++i){
        ans.push_back(make(i, i+1, BIT(i-1)));
        ans.push_back(make(i, i+1, 0));
    }
    for(int i=N-1;i>0;--i){
        if(L-BIT(i-1)>=BIT(r)){
            ans.push_back(make(i, N, L-BIT(i-1)));
            L-=BIT(i-1);
            ++M;
        }
    }
    cout << N << " " << M << endl;
    for(int i=0;i<ans.size();++i){
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
    }
    return 0;
}
