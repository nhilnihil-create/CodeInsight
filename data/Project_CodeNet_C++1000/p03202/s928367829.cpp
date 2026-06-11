#include<bits/stdc++.h>
#define mo 1000000007
#define pi 3.1415926535898
#define eps 1e-9 
using namespace std;
long long read(){
    long long xx=0,flagg=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')
        ch=getchar();
    if(ch=='-'){
        flagg=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        xx=xx*10+ch-'0';
        ch=getchar();
    }
    return xx*flagg;
}
void pus(long long xx,long long flagg){
    if(xx<0){
        putchar('-');
        xx=-xx;
    }
    if(xx>=10)
        pus(xx/10,0);
    putchar(xx%10+'0');
    if(flagg==1)
        putchar(' ');
    if(flagg==2)
        putchar('\n');
    return;
}
int n,i,j,a[200005],l,r,mid,min1,flag;
int tail,zhan[200005];
map<int,int> mp;
map<int,int> :: iterator it;
int main(){
    n=read();
    for(i=1;i<=n;i++){
        a[i]=read();
        if(a[i]<=a[i-1]&&i!=1)
            flag=1;
    }
    if(flag==0){
        pus(1,2);
        return 0;
    }
    l=2;r=n;mid=(l+r)/2;min1=r;
    while(l<=r){
        tail=0;flag=0;
        for(i=2;i<=n;i++)
			if(a[i]<=a[i-1]){
	            
	            while(mp.size()!=0){
	            	it=mp.end();
	            	it--;
	            	if((it->first)>a[i])
	            		mp.erase(it);
	            	else
	            		break;
	            }
				mp[a[i]]++;
	            j=a[i];
	            while(mp[j]==mid){
	            	mp[j]=0;
	            	j--;
	            	mp[j]++;
	            }
	            if(j==0){
	            	flag=1;
	            	break;
	            }
	        }
        if(flag==1)
            l=mid+1;
        else{
            r=mid-1;
            min1=min(min1,mid);
        }
        mid=(l+r)/2;
        mp.clear();
    }
    pus(min1,2);
}