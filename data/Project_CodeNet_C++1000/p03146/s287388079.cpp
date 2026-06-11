/*
      author  : nishi5451
      created : 14.08.2020 23:15:15
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int s;
    cin >> s;
    map<int,int> mp;
    int index = 1;
    int value = s;
    while(1){
        if(mp[value]){
            cout << index << endl;
            return 0;
        }
        else{
            mp[value]++;
        }
        index++;
        if(value%2==0){
            value = value/2;
        }
        else{
            value = 3*value+1;
        }
        //cout << index << "-" << value << endl;
    }
    return 0;
}