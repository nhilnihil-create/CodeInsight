#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int N,M;
    cin >> N >>M;
    map<int,int> mp;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int num;
            cin >> num;
            mp[num]++;
        }
    }
    int count = 0;
    for(auto it : mp){
        if(it.second==N){
            count++;
        }
    }
    cout << count <<endl;
}