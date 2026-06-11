#include<cstdio>
int main(){
        int n,a[100000],b[100000],max=0,min=1000000000,m;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
                if(a[i]>max){
                        max=a[i];
                }
        }
        for(int i=0;i<n;i++){
                if(max>=2*a[i]){
                        b[i]=max-2*a[i];
                }
                else{
                        b[i]=2*a[i]-max;
                }
                if(min>=b[i]){
                        min=b[i];
                        m=i;
                }
        }
        printf("%d %d",max,a[m]);
}