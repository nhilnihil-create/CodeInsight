#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[200000+100];
map<int,int>sz;
set<int>S;
int calcu(int n,int q)
{
    int times=0;
    while(n)
    {
        n/=q;
        times++;
    }
    return times;
}
int my_min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int n;
    bool flag=true;
    int min = 1000000007;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(i!=0 && num[i] <=num[i-1])
            flag=false;
        min=my_min(min,num[i]);
    }
    if(flag)
        printf("1\n");
    else
    {
        int star=2;
        int end=n;
        while(star<=end)
        {
            int mid=(star+end)/2;
            int limit=calcu(n,mid);
            if(min>=limit)
                end=mid-1;
            else
            {
                bool flagg=true;
                sz.clear();
                S.clear();
                int len=num[0];
                for(int i=1;i<n;i++)
                {
                	len=num[i];
                    if(num[i]>num[i-1])
                    {
                        sz.erase(sz.lower_bound(num[i-1]),sz.end());
					} 
                    else
                    {
                    	set<int> ::iterator it; 
                    	it=S.lower_bound(num[i]);
							{
		                        int k=len-1;
		                        while(k>=0 && sz[k]==mid-1)
		                        {
		                            sz[k]=0;
		                            k--;
		                        }
		                        if(k==-1)
		                        {
		                            flagg=false;
		                            break;
		                        }
		                        sz[k]++;
	                    	}
                    }
          //          for(int k=0;k<len;k++)
            //            printf("%d ",sz[k]);
             //       printf("\n");
                }
                
                if(!flagg)
                    star=mid+1;
                else
                    end=mid-1;
            }
        }
        printf("%d\n",star);
    }
    return 0;
}