#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int MOD = 1000000007;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    int p[N];
    for(int i=0;i<N;i++){
        cin >> p[i];
    }
    
    int a=0,b=0,c=0;
    for(int i=0;i<N;i++){
        if(p[i]>B) c++;
        else if(p[i]>A) b++;
        else a++;
    }
    
    cout << min({a,b,c}) << endl;
    return 0;
}
