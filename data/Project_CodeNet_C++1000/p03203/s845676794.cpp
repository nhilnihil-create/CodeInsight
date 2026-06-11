#include <iostream>
#include <algorithm>

using namespace std;

const int MAXK=200111;

int N, M, K;

struct Node{
	int x, y;
	Node(){}
	Node(int _x, int _y){x=_x;y=_y;}
} T[MAXK], At;

bool cmpxy(Node A, Node B){
	if(A.x==B.x)	return A.y<B.y;
	return A.x<B.x;
}

void Go(Node &at, Node P){
	P.x-=(at.x-1);P.y-=(at.y-1);
	if(P.x<P.y){
		at.x+=P.x-1;at.y+=P.x-1;
	}
	else if(P.y<P.x){
		at.x+=P.x-2;at.y+=P.x-1;
	}
	else	{at.x+=P.x-1;at.y+=P.x-2;}
}

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M >> K;
	
	for(int i=1;i<=K;++i)	cin >> T[i].x >> T[i].y;
	
	sort(T+1, T+K+1, cmpxy);
	T[++K]=Node(N+1, 0);
	
	At=Node(1, 1);
	for(int i=1;i<=K;++i){
		if(i>1 && T[i].x==T[i-1].x)	continue;
		Go(At, T[i]);
		if(At.x!=T[i].x)	break;
	}
	
	cout << At.x << endl;
	
	return 0;
}