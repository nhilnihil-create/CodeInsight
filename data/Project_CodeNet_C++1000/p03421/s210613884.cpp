#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

const int N = 4e5;
int A[N], B[N];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    if(((ll)a*(ll)b<(ll)n) || (a+b>n+1)){
        puts("-1");
        return 0;
    }
    
    int i, j;
    for(i=1; i<=n; i++)
        A[i] = i;
    
    if(b!=1){
        int t = (n-a);
        for(i=0; i<t/(b-1); i++){
            for(j=1; 2*j<=b; j++){
                int temp = A[b*i+j];
                A[b*i+j] = A[b*i+b-j+1];
                A[b*i+b-j+1] = temp;
            }
        }

        int l = t%(b-1)+1;
        for(j=1; 2*j<=l; j++){
            int temp = A[b*i+j];
            A[b*i+j] = A[b*i+l-j+1];
            A[b*i+l-j+1] = temp;
        }
    }

    for(i=1; i<=n; i++)
        printf("%d ", A[i]);      

    return 0;
}