#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MAX 200005
int h[MAX],v[MAX],a[MAX],tree[MAX*4];
void update(int ss, int se, int i, int diff, int si)  
{  
    if (i < ss || i > se)  
        return; 
	if(ss==se) 
    tree[si] = tree[si] + diff;  
    else
    {  
        int mid = (ss+se)/2;  
        update( ss, mid, i, diff, 2*si + 1);  
        update( mid+1, se, i, diff, 2*si + 2);  
        tree[si]=max(tree[2*si+1],tree[2*si+2]);
    }  
}  
int query(int ss, int se, int qs, int qe, int si) 
{ 
	if (ss>se || ss>qe || se<qs) 
		return 0; 
	if (ss>=qs && se<=qe) 
		return tree[si]; 
	int mid = (ss + se)/2; 
	return max(query(ss, mid, qs, qe, 2*si+1) ,
		query(mid+1, se, qs, qe, 2*si+2)); 
}  
signed main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>h[i];
	for(i=0;i<n;i++)
	cin>>v[i];
	int m=0;
	memset(tree,0,sizeof(tree));
	for(i=0;i<n;i++)
	{
		int l=query(0,n,0,h[i]-1,0);
		m=max(l+v[i],m);
		update(0,n,h[i],l+v[i],0);
	}
	cout<<m<<"\n";
}