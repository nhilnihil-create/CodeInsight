#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int A,B;
    map<int,int>mp;
    for(int i = 0; i < 3;i++){
        cin >> A >> B;
        mp[A]++;
        mp[B]++;
    }
    
    if(mp[1]<=2
    && mp[2]<=2
    && mp[3]<=2
    && mp[4]<=2)cout << "YES"<<endl;
    else cout <<"NO"<<endl;
    
    
}
    
    

