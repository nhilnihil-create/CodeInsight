#include<iostream>
#include<vector>
using namespace std;

class Line{
public:
  int x;
  int y;
  int d;
  Line(int _x,int _y,int _d){
	x=_x;
	y=_y;
	d=_d;
  }
};

int main(){
  int L;
  cin >> L;
  int r=0;
  int x=1;
  for(int i=0;i<20;i++){
	x*=2;
	r++;
	if(x*2>L){
	  break;
	}
  }

  vector<Line> v;
  for(int i=0;i<r;i++){
	Line t1(i,i+1,0);
	Line t2(i,i+1,1<<i);
	v.push_back(t1);
	v.push_back(t2);
  }
  for(int i=r-1;i>=0;i--){
	if(L-(1<<i)>=(1<<r)){
	  Line t(i,r,L-(1<<i));
	  v.push_back(t);
	  L-=(1<<i);
	}
  }
  cout << (r+1) << " " << v.size() << endl;
  for(int i=0;i<v.size();i++){
	cout << v[i].x+1 << " " << v[i].y+1 << " " << v[i].d << endl;
  }
  
  return 0;
}