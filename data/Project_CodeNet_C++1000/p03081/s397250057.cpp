#include<cstdio>
char s[200001];
char t[200001], d[200001];

int isLeftDead(int p,int q,int n){
	int ok = 0;
	for(int i = 1; i <= q; i++){
		if(t[i]==s[p]){
			if(d[i]=='L'){
				p--;
				if(p==0){
					ok = 1;
					break;
				}
			}
			else{
				p++;
				if(p==n+1){
					ok = 0;
					break;
				}
			}
		}
	}
	return ok;
}

int isRightDead(int p,int q,int n){
	int ok = 0;
	for(int i = 1; i <= q; i++){
		if(t[i]==s[p]){
			if(d[i]=='L'){
				p--;
				if(p==0){
					ok = 0;
					break;
				}
			}
			else{
				p++;
				if(p==n+1){
					ok = 1;
					break;
				}
			}
		}
	}
	return ok;
}

int main(){
	int n,q;
	scanf("%d%d%s",&n,&q,s+1);
	for(int i = 1; i <= q; i++){
		char a[2], b[2];
		scanf("%s%s",a,b);
		t[i] = a[0], d[i] = b[0];
	}
	int l = 1, r = n;
	int leftRes = 0;
	while(l<=r){
		int m = (l+r)/2;
		if(isLeftDead(m,q,n)){
			leftRes = m;
			l = m+1;
		}
		else r = m-1;
	}
	l = 1, r = n;
	int rightRes = n+1;
	while(l<=r){
		int m = (l+r)/2;
		if(isRightDead(m,q,n)){
			rightRes = m;
			r = m-1;
		}
		else l = m+1;
	}
	//printf("left = %d, right = %d\n",leftRes,rightRes);
	int ans = n-leftRes-(n-rightRes+1);
	printf("%d\n",ans);
	return 0;
}
