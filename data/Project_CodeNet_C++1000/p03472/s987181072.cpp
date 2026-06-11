#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){

    int N;
    long long H;
    cin >> N >> H;
    long long a,b;
    vector<pair<long long,int>> vec;
    
    for(int i = 0; i < N;i++){
        cin >> a >> b;
        vec.push_back(make_pair(a,0));
        vec.push_back(make_pair(b,1));
    }
    
    sort(vec.begin(),vec.end(),greater<pair<long long,int>>());
    int index = 0;
    int cont = 0;
    while(H>0){
        //cout << vec[index].first <<" "<< vec[index].second << endl;
        if(vec[index].second == 0){
            while(H>0){H-=vec[index].first;cont++;}
        }else{
            H -= vec[index].first;
            cont++;
        }
        index++;
    }
    cout << cont << endl;
    
}

