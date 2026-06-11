#include <iostream>
#include <vector>
using namespace std;
 
int N,Q;
string s;
vector<vector<char>> ju;
 
bool isdeadleft(int xp){
    int oxp = xp;
    for (int i=0; i<Q; i++){
    	char comp = ju[i][0];
    	char comm = ju[i][1];
    	if (s[xp] == comp) {
    		if (comm == 'L') {
	    		xp -= 1;
    		} else {
    			xp += 1;
    		}
    	}
    	if (xp < 0){
    		return true;
    	}
    	if (xp > N-1){
    		xp = N-1;
    	}
    }
    return false;
}
bool isdeadright(int xp){
    int oxp = xp;
    for (int i=0; i<Q; i++){
    	char comp = ju[i][0];
    	char comm = ju[i][1];
    	if (s[xp] == comp) {
    		if (comm == 'L') {
	    		xp -= 1;
    		} else {
    			xp += 1;
    		}
    	}
    	if (xp < 0){
    		xp=0;
    	}
    	if (xp > N-1){
    		return true;
    	}
    }
    return false;
}
 
int mid(int x1, int x2){
    return (int)((x1+x2)/2);
}
 
 
int main(void){

  cin >> N >> Q;
  cin >> s;
  for (int i=0; i<Q; i++){
  	char c1,c2;
  	cin >> c1 >> c2;
  	ju.emplace_back(vector<char>({c1,c2}));
  }
 
  int p1, p2, p3, ap;
 
if (isdeadleft(N-1) || isdeadright(0)){
    cout<<0<<endl;
    exit(0);
}
 
//left
p1 = 0;
p3 = N-1;
p2 = mid(p1,p3);
while (p3 - p1 != 1){
    if (isdeadleft(p2)){
    	p1 = p2; p2 = mid(p2,p3);
    } else {
    	p3 = p2; p2 = mid(p1,p2);
    }
}
int p;
if (isdeadleft(p1)){
	p = p3;
} else {
	p = p1;
}
//right
p1 = 0;
p3 = N-1;
p2 = mid(p1,p3);
while (p3 - p1 != 1){
    if (isdeadright(p2)){
        p3 = p2;
        p2 = mid(p1,p2);
    } else {
        p1 = p2;
        p2 = mid(p2,p3);
    }
}
int q;
if (isdeadright(p3)){
	q = p1;
} else {
	q = p3;
}
 
if (p > q){
	cout << 0 << endl;
} else {
    cout << q-p+1 << endl;
}
 
 
  return 0;
}