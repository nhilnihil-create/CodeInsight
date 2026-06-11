#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,x,a;
    cin>>n>>x;
    std::deque<long long int> deq;
    for (int i=0;i<n;i++) {
        cin>>a;
        deq.emplace_back(a);
    }
    sort(deq.begin(),deq.end());
    long long int count=0;
    for (int i=0;i<n;i++) {
        if (x-deq[i]>=0) {
            count++;
            x-=deq[i];
        } else {
            cout<<count<<endl;
            return 0;
        }
    }
    if (x>0) {
        cout<<count-1<<endl;
    } else {
        cout<<count<<endl;
    }
}