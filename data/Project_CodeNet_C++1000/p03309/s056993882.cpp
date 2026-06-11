#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    long long int a;
    std::deque<long long int> deq;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    std::deque<long long int> diff;
    for (int i=1;i<=n;i++) {
        diff.emplace_back(deq[i-1]-i);
    }
    sort(diff.begin(),diff.end());
    long long int sum=0;
    for (int i=1;i<=n;i++) {
        sum+=abs(deq[i-1]-(diff[diff.size()/2]+i));
    }
    cout<<sum<<endl;
}