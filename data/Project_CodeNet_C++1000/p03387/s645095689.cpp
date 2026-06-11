#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> x(3);
    for(int i=0; i<3; i++){
        cin >> x.at(i);
    }
    sort(x.begin(), x.end());
    int cnt = 0;
    cnt+=x.at(2)-x.at(1);
    if((x.at(2)-(x.at(0)+cnt))%2==1){
        cnt+=(x.at(2)-(x.at(0)+cnt))/2+2;
    }else{
        cnt+=(x.at(2)-(x.at(0)+cnt))/2;
    }
    cout << cnt << endl;
    return 0;
}