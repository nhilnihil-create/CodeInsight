#include <bits/stdc++.h>
using namespace std;
struct Node{
	int from,to,dis;
	Node(int f=0,int t=9,int d=0):from(f),to(t),dis(d){}
}; 
int pow2[30]={1};
vector<Node> V;
inline int lowbit(int x)
{
	return (x & (-x));
}
int main()
{
	int L;
	for(int i=1;i<=20;i++)
		pow2[i] = pow2[i-1]<<1;
	while(scanf("%d",&L)!=EOF)
	{
		V.clear();
		for(int i=19;i>=2;i--)
		{
			V.push_back(Node(i,i+1,0));
			V.push_back(Node(i,i+1,pow2[19-i]));
		}
		int bit = floor(log2(L))+1; //二进制的位数
		//V.push_back(Node(1,22-bit,0)); 
		int x = L;
		while(x)
		{
			int y = lowbit(x);  
			bit = floor(log2(y))+1;
			x -= y;
			bitset<20> xx(x),yy(y);
			//cout<<"x = "<<xx<<"  y = "<<yy<<endl;
			if(bit==20) 
			{
				V.push_back(Node(1,2,0));
				V.push_back(Node(1,2,pow2[18]));
				break;
			}
			V.push_back(Node(1,21-bit,x)); 
		}
		int edge = V.size();
		printf("20 %d\n",edge);
		for(int i=0;i<edge;i++)
		{
			printf("%d %d %d\n",V[i].from,V[i].to,V[i].dis);
		}
		
	}
	
	
	
	
	return 0;
} 