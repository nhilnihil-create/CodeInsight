  #include <bits/stdc++.h>
  #define rep(i,n) for(int i=1;i<=n;i++)
  using namespace std;
    int main(){
        int n,a,b;
        cin >> n >> a >> b;
        int ans=0;
        rep(i,n){
       int h=0;
        int s=0;
            s=i;
            if(s<10){
            h=s;
            }
            else{ 
            while(s>=10){
              h+=s%10;
              s/=10;
            }
            h+=s;
            }
            //cout << h << endl;
            if(a<=h && h<=b){
                ans+=i;
            }
        }
          cout << ans << endl;
          return 0;
    }