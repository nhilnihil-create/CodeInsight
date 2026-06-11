#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
 vector<vector<char>> c(2,vector<char>(3));
 rep(i,2){
    rep(j,3){
       cin >> c.at(i).at(j);
    }
 }
 bool a=true;
 if(c.at(0).at(0)!=c.at(1).at(2))a=false;
 else if(c.at(0).at(1)!=c.at(1).at(1))a=false;
 else if(c.at(0).at(2)!=c.at(1).at(0))a=false;
 if(a)cout << "YES" << endl;
 else cout << "NO" << endl;
}