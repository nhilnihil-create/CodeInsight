#include <bits/stdc++.h>
using namespace std;
int main(void){
    std::deque<int> deq(100001,0);
    deq[2]=1;
    for (int i=3;i<=100000;i+=2) {
        double sqrtNum=sqrt(i);
        int flag=0;
        for (int j=3;j<=sqrtNum;j+=2) {
            if (i%j==0) {
                flag=1;
                break;
            }
        }
        if (flag==0) {
            deq[i]=1;
        }
    }
    std::deque<int> nums(100001,0);
    for (int i=3;i<=100000;i+=2) {
        if (deq[i]==1) {
            if (deq[(i+1)/2]==0) {
                nums[i]=0;
            } else {
                nums[i]=1;
            }
        }
    }
    std::deque<int> s(100002,0);
    for (int i=0;i<=100000;i++) {
        s[i+1]=s[i]+nums[i+1];
    }
    int q,l,r;
    cin>>q;
    for (int i=0;i<q;i++) {
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
    }
}