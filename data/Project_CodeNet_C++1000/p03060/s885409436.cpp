#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;

int main(){
    int n;
    cin >> n ;
    vector<int> v(n);
    // vector<int> c(n);
    for(int i=0;i<n;i++)cin >> v.at(i);
    int c;
    int ans=0;
    for(int i=0;i<n;i++){
        cin >> c;
        if(v.at(i)-c>0) ans+= (v.at(i)-c);
    }
    cout << ans << endl;

    return 0;
}