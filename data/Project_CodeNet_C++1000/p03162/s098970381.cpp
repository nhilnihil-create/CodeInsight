#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>Arr(3);
    for(int day=0; day<n; day++){
        vector<int> curr(3),newArr(3);
        for(int task=0; task<3; task++){
            cin>>curr[task];
            for(int prvTask=0; prvTask<3; prvTask++){
                if(prvTask==task)continue;
                newArr[task]=max(newArr[task],Arr[prvTask]+curr[task]);
            }
        }
        Arr=newArr;
    }

    cout<<max({Arr[0],Arr[1],Arr[2]})<<endl;

    return 0;
}