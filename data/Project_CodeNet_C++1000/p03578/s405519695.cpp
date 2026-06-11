#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    long long D;
    map<long long,int>mp;
    for(int i = 0; i < N; i++){
        cin >> D;
        mp[D]++;
    }
    
    int M;
    cin >> M;
    
    long long T;
    for(int i = 0; i < M; i++){
        cin >> T;
        if(mp[T]==0){
            cout << "NO"<<endl;
            return 0;
        }else{
            mp[T]--;
        }
    }
    
    cout << "YES"<<endl;
    return 0;
    
}

    
    

