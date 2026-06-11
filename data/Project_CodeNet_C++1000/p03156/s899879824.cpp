#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,a,b,p;
    cin>>n>>a>>b;
    std::deque<int> deq;
    for (int i=0;i<n;i++) {
        cin>>p;
        deq.emplace_back(p);
    }
    sort(deq.begin(),deq.end());
    int count1=0,count2=0,count3=0;
    for (int i=0;i<n;i++) {
        if (deq[i]<=a) {
            count1++;
        }
    }
    for (int i=0;i<n;i++) {
        if (deq[i]>=a+1&&deq[i]<=b) {
            count2++;
        }
    }
    for (int i=0;i<n;i++) {
        if (deq[i]>=b+1) {
            count3++;
        }
    }
    cout<<min(count1,min(count2,count3))<<endl;
}