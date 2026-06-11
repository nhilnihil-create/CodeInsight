#include <bits/stdc++.h>
using namespace std;

int h, w, n, xi, yi;

int main(){
	scanf("%d %d %d", &h, &w, &n);
	
	set < pair <int, int> > s;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &xi, &yi);
		xi--, yi--;
		
		s.insert(make_pair(yi, xi));
	}
	
	for(int i = 0; i < w; i++)
		s.insert(make_pair(i, h));
		
	int x = 0, y = 0, res = h;
	while(x < w){
		auto d = s.lower_bound(make_pair(x, y));
		res = min(res, d->second);
		
		bool moved = false;
		while(true){
			if(s.count(make_pair(x, y + 1))){
				break;
			}
			y++;
			
			if(!s.count(make_pair(x + 1, y))){
				x++;
				moved = true;
				break;
			}
		}
		
		if(!moved)break;
	}
	printf("%d\n", res);
	
	return 0;
}
