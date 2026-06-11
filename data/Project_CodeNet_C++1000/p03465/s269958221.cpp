#include<bits/stdc++.h>
using namespace std;

int n,a,sum=0;
bitset<2000007>jojo;
//C++的 bitset在bitset头文件中它是一种类似数组的结构它的每一个元素只能是０或１每个元素仅用１bit空间

int main(){
    scanf("%d",&n);
    jojo[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        jojo|=jojo<<a;
        sum+=a;
    }
    for(int i=(sum+1)/2;i<=sum;i++){
        if(jojo[i]){
		printf("%d\n",i);
		break;
		}
    }
    return 0;
}