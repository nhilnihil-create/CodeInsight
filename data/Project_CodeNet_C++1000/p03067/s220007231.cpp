#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

bool jugdg(int x[],int size,int t){
    for(int i=0;i<size;i++){
        if(t==x[i])
            return false;
    }
    return true;
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a<c&&b>c){
        puts("Yes");
    }else if(b<c&&a>c){
        puts("Yes");
    }else{
        puts("No");
    }

    return 0;
}