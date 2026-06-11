#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換

int main() {
   int d,g;
   cin>>d>>g;
   int p[d],c[d];
   rep(i,d){
       cin>>p[i]>>c[i];
   }
   int ans=INF;
    for(int bit = 0; bit < (1<<d); ++bit){
        int count=0,mx=-1,cnt=0;
        for(int i = 0; i < d; ++i){
            if(bit & (1<<i)){
                count+=100*(i+1)*p[i]+c[i];
                cnt+=p[i];
            }else
            {
                mx = i;
            }
        }
        //cout<<count<<endl;
        if(count < g && mx != -1){
            rep(i,p[mx]){
                count+=100*(mx+1);
                cnt++;
                if(count >= g) break;
            }
        }
        
        if(count >= g)
        ans=min(ans,cnt);
        
    }
    cout<<ans<<endl;
    return 0;
}
