    #include<bits/stdc++.h>
    #define REP(i,n) for(long long i=0;i<(long long)n;i++)
    //#define _GLIBCXX_DEBUG
    using namespace std;
    using ll = long long;
    using Pi = pair<int,int>;
    using Pl = pair<ll,ll>;
    using Vl = vector<ll>;
    using vi = vector<int>;
    using Graph = vector<vi>;
    
    int main(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        //std::cout << std::fixed << std::setprecision(15); //"for float-base problem"
        int N,A,B;
      cin>>N;
      if(N==1){
        cout << "Hello World" << endl;
        return 0;
        }else{
        cin >> A >> B;
        cout << A+B<< endl;
      }
      return 0;}