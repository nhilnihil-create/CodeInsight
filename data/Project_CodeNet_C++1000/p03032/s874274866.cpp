#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 51
int mutton[MAXN];
int plate[MAXN];

int main()
{
    int N,K,res=0;
    cin>>N>>K;
    
	for(int i=0;i<N;i++)
		cin>>mutton[i];
	
	int bound=min(N,K);
	for(int l=0;l<=bound;l++)
	{
		for(int r=0;r<=bound-l;r++)
		{
			int i,j;
			for(i=0;i<l;i++)
				plate[i]=mutton[i];
			for(j=0;j<r;j++)
				plate[i+j]=mutton[N-j-1];

			sort(plate,plate+l+r);

			int k=0,temp=0;
			while(k+l+r<K&&plate[k]<0)
				k++;
			while(k<l+r)
			{
				temp+=plate[k];
				k++;
			}
			
			res=max(res,temp);
		}
	}
	cout<<res<<endl;
    return 0;
}

