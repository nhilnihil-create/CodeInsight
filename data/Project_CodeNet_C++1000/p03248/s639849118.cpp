#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int N = 1e5 + 5;

char s[N];

signed main(){
	scanf("%s", s+1);	
    int n = strlen(s+1);
    for(int i=1; i<n; i++)
        if(s[i] != s[n-i]){
            cout << -1;
            return 0;
        }
    
    if(s[1] == '0' || s[n-1] == '0' || s[n] == '1'){
        cout << -1;
        return 0;
    }
    
    int pre = 1;
    for(int i=2; i<=n/2; i++){
        if(s[i] == '0') continue;
		
        for(int j=pre; j<i; j++)
            printf("%d %d\n", i, j);
        pre = i;
    }
	
    for(int i=pre; i<n; i++)
        printf("%d %d\n", n, i);
        
    return 0;
}