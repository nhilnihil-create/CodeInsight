#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <unordered_map>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int v[N];
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    vector<int> e,o;
    for(int i=0;i<N;i++){
        if(i % 2){
            o.push_back(v[i]);
        }
        else{
            e.push_back(v[i]);
        }
    }
    int E1 =0,O1=0,E2=0,O2=0;
    int count_E1 = 0,count_E2 = 0,count_O1 = 0,count_O2 = 0;
    unordered_map<int,int> m1,m2;
    for(int i=0;i<o.size();i++){
        m1[o[i]]++;
        if(count_O1 < m1[o[i]]){
            O1 = o[i];
            count_O1 = m1[o[i]];
        }
        else if(count_O2 < m1[o[i]]){
            O2 = o[i];
            count_O2 = m1[o[i]];
        }
    }
    for(int i=0;i<e.size();i++){
        m2[e[i]]++;
        if(count_E1 < m2[e[i]]){
            E1 = e[i];
            count_E1 = m2[e[i]];
        }
        else if(count_E2 < m2[e[i]]){
            E2 = e[i];
            count_E2 = m2[e[i]];
        }
    }
    int ans;
    if(E1 != O1){
        ans = N - count_O1 - count_E1;
    }
    else{
        ans = min(N - count_O2 - count_E1,N - count_O1 - count_E2);
    }
    cout << ans;
}
