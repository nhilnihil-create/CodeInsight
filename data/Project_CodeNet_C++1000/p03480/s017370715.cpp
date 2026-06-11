#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
    string S;
    cin >> S;
    char now=S[0];
    int place=0;
    int center;
    if(S.size()%2==1){
        center=(S.size()+1)/2;//真ん中がcenter番目
    }else{
        center=-1;
    }
    int ans=S.size();
    for(int i=1; i<S.size(); i++){
        if(now!=S[i]){
            now=S[i];
            if(center!=-1){
                if(i+1<=center) ans=min(ans, (int)S.size()-i);
                else ans=min(ans, i);
            }else{
                if(i+1<=S.size()/2) ans=min(ans, (int)S.size()-i);
                else ans=min(ans, i);
            }
        }
    }
    cout << ans << endl;


    return 0;
}
