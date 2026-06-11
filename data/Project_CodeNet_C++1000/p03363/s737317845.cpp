#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long int a;
    cin>>n;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    std::deque<long long int> s(n+1,0);
    std::map<long long int, long long int> map;
    for (int i=0;i<n;i++) {
        s[i+1]=s[i]+deq[i];
    }
    for (int i=0;i<n+1;i++) {
        map[s[i]]++;
    }
    long long int sum=0;
    for (auto itr=map.begin();itr!=map.end();itr++) {
        sum+=(itr->second)*(itr->second-1)/2;
    }
    cout<<sum<<endl;
}