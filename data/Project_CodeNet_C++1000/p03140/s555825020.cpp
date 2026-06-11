#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;
 
int main(){
    
    int N,ans,y;
    string A,B,C;

    ans = 0;
    cin >> N>>A>>B>>C;

    for(int i=0;i<N;i++){
        y=0;
        if(B[i]!=A[i]){
            y+=1;
        }
        if(C[i]!=A[i]&&C[i]!=B[i]){
                y+=1;
        }
        ans+=y;
    }

    cout << ans;

    return 0;

}