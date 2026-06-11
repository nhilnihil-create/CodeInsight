#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a;
    vector<int> q(4,0);
    for (int i=0;i<6;i++){cin >> a;q[a-1]++;}
    auto mq = max_element(q.begin(),q.end());
    cout << ((*mq==3) ? "NO" : "YES") << endl;
    return 0;
}