#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<pair<long, long> > dishes(N);
    long tmpa, tmpb;
    for(int i=0;i<N;++i){
        cin>>tmpa>>tmpb;
        dishes[i] = make_pair(tmpa+tmpb, tmpa);
    }
    sort(dishes.begin(), dishes.end());
    long a=0;
    long b=0;
    for(int i=0;i<N;++i){
        if(i%2==0) a += dishes[N-i-1].second;
        else b += dishes[N-i-1].first - dishes[N-i-1].second;
    }
    cout<<a-b<<endl;
}
