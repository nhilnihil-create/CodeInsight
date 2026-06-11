//Rated for Me
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string>contest={
        "ABC",
        "ARC",
        "AGC",
    };
    int R;
    cin>>R;
    int idx;
    if(R<1200)idx=0;
    else if(R<2800)idx=1;
    else      idx=2;
    cout<<contest.at(idx)<<endl;

    return 0;
}
