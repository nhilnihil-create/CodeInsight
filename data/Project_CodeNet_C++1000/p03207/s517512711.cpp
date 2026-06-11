 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;

 int main(){
     int n;
     cin >> n;
     vector<int> p(n);
     rep(i,n){
         cin >> p[i];
     }
     int a = max_element(p.begin(),p.end())-p.begin();
     p[a]/=2;
     int sum=0;
     rep(i,n){
         sum+=p[i];
     }
     cout << sum << endl;
     return 0;
 }