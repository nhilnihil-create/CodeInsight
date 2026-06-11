    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0;i<(int)(n);i++)
    #define ll long long
    #define BIT_FLAG_0 (1<<0) // 0000 0000 0000 0001
    int gcd(int a, int b){
        if(a%b == 0){
            return b;
        }else{
        return gcd(b, a%b);
        }
    }
     
    int main(){
        int n,m,c,count=0;
        cin >> n >> m >> c;
        vector<int> b(m);
        vector<vector<int>> a(n,vector<int>(m));
        rep(i,m) cin >> b[i];
        rep(i,n){
            rep(j,m){
                cin >> a[i][j];
            }
        }
        rep(i,n){
            ll sum=0;
            rep(j,m){
                sum+=b[j]*a[i][j];
            }
            sum+=c;
            if(sum>0) count++; 
        }
        cout << count << endl;
        return 0;
    }