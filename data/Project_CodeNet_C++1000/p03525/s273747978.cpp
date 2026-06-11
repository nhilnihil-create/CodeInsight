#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int n;
    cin >> n;
    vector<int> da(12,0);
    int x;
    rip(i,n,0){
        cin >> x;
        if(x==0){
            cout << 0 << endl;
            return 0;
        }
        da[x-1]++;
    }
    vector<bool> time(24,false);
    time[12]=true;
    int ju=1;
    rip(i,11,0){
        if(da[i]>2){
            cout << 0 << endl;
            return 0;
        }
        else if(da[i]==2){
            time[11-i]=true;
            time[13+i]=true;
        }
        else if(da[i]==1){
            if(ju){
                time[12+ju*(i+1)]=true;
                ju*=-1;
            }
        }
    }
    if( da[11]>1){
        cout << 0 << endl;
        return 0;
    }
    if(da[11]){
        time[0]=true;
    }
    int ans=30,now=12,div=13;
    while(div!=12){
        if(time[div]){
            ans=min(ans,min(abs(div-now),24-abs(div-now)));
            now=div;
        }
        div=(div+1)%24;
    }
    cout << ans << endl;
}