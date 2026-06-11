#include "./bits/stdc++.h"
using namespace std;

vector<int> p;
int v;


int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&v);
        p.push_back(v);
    }
    sort(p.begin(),p.end());
    int max = p[p.size()-1];
    p.pop_back();
    p.push_back(max/2);
    cout << accumulate(p.begin(),p.end(),0)<< endl;
    
    
    return 0;
}