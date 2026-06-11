#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    string s;
    cin>>n>>s;
    std::deque<int> W;
    std::deque<int> E;
    int w_cnt=0,e_cnt=0;
    for (int i=0;i<n;i++) {
        if (s.at(i)=='W') {
            w_cnt++;
            W.emplace_back(w_cnt);
            E.emplace_back(e_cnt);
        } else if (s.at(i)=='E') {
            e_cnt++;
            E.emplace_back(e_cnt);
            W.emplace_back(w_cnt);
        }
    }
    int min_cnt=1000000;
    for (int j=0;j<n;j++) {
        int count=0;
        if (j==0) {
            count+=E[n-1];
        } else if (j==n-1) {
            count+=W[n-1];
        } else {
            //左側
            count+=W[j-1];
            //右側
            count+=E[n-1]-E[j];
        }
        if (count<min_cnt) {
            min_cnt=count;
        }
    }
    cout<<min_cnt<<endl;
}