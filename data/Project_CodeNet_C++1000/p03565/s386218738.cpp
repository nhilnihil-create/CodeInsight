  #include <bits/stdc++.h>
  using namespace std;

  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}

  const ll MOD=1e9+7;

  void solve(){
     string s;
     cin >> s;
     int n = s.size();
     string t;
     cin >> t;
     int m = t.size();
     string ans = string(n,'z');
     for(int i=0;i+m-1<n;i++){
        bool ok = true;
        for(int j=0;j<m;j++){
           if((s[i+j]==t[j]) || (s[i+j]=='?'));
           else ok = false;
        }
        if(ok){
           string k = s.substr(0,i)+t+s.substr(i+m);
           for(int j=0;j<k.size();j++){
               if(k[j]=='?')k[j]='a';
           }
           ans = min(ans,k);
        }
     }
     if(ans == string(n,'z'))
     cout << "UNRESTORABLE";
     else cout << ans;
  }


  int main(){
    IOS
       solve();
       cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
