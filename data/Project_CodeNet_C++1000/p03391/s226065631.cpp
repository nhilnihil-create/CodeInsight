#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int N;
int a[200010],b[200010];

int main(){
    cin>>N;
    int mB=2001001001;
    LL sum=0;
    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i];
        if(a[i]>b[i] && b[i] < mB){
            mB = b[i];
        }
        sum += b[i];
    }
    if(mB>=2001001001){
        cout<<0<<endl;
        return 0;
    }
    cout << sum - mB <<endl;
    return 0;
}