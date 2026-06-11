#include "bits/stdc++.h"


using namespace std;


int main(){
    vector<int> vec(3);

    for(int i=0;i<3;i++){
        cin>>vec[i];
    }

    sort(vec.begin(),vec.end());

    int ans = vec[0]+(vec[1]+10*vec[2]);

    cout << ans << endl;


    return 0;
}