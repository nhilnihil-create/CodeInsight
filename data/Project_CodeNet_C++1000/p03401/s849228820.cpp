#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a;
    cin>>n;
    std::deque<int> deq;
    deq.emplace_back(0);
    int sum=0;
    for (int i=0;i<=n;i++) {
        if (i!=n) {
            cin>>a;
            deq.emplace_back(a);
            sum+=abs(deq[i]-deq[i+1]);
        } else {
            deq.emplace_back(0);
            sum+=abs(deq[i]-0);
        }
    }
    for (int j=1;j<=n;j++) {
        int tmp=sum;
        tmp-=abs(deq[j-1]-deq[j]);
        tmp-=abs(deq[j]-deq[j+1]);
        tmp+=abs(deq[j-1]-deq[j+1]);
        cout<<tmp<<endl;
    }
}