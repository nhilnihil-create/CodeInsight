
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){

     int n; cin>>n;
   char x;
     set<char>ani;
     for(int i=0;i<n;i++)  {
       cin>>x;
       ani.insert(x); }

       if(ani.size() == 3 ) cout<<"Three"<<endl;
       else if(ani.size() == 4)
            cout<<"Four"<<endl;


  return 0;
 }
