
#include <bits/stdc++.h>
using namespace std;

typedef struct _jwe{
    int v;
    int c;
}Jew;
int main(void){

    int N,ans=0;
    cin >> N;
    Jew j[N];
    
    for(int i=0;i<N;i++){
        cin >> j[i].v;
    }
    for(int i=0;i<N;i++){
        cin >> j[i].c;
    }

    for(int i=0;i<N;i++){
        if(j[i].v - j[i].c > 0) ans+= (j[i].v - j[i].c);
    }
    
    cout << ans << endl;
}