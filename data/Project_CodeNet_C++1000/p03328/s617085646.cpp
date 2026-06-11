#include <bits/stdc++.h>
using namespace std;
int main(void){
    std::deque<int> deq;
    int tmp=0;
    for (int i=1;i<=999;i++) {
        tmp+=i;
        deq.emplace_back(tmp);
    }
    int a,b;
    cin>>a>>b;
    for (int j=0;j<deq.size()-1;j++) {
        if (deq[j]-a==deq[j+1]-b) {
            cout<<deq[j]-a<<endl;
            break;
        }
    }
}
