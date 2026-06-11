#include<stdio.h>
#include<string.h>
int a[100000+100];
int main(){
	    int n,m;
	    scanf("%d%d",&n,&m);
	    int minx=0;
	    memset(a,0,sizeof(a));
	    for(int i=1;i<=m;i++){        //把岛的左端和右端存起来
		    int x,y;        
		    scanf("%d%d",&x,&y);
		        if(minx==0){
			        minx=x;        //找最小到有争端的岛的左端
		        }
		        if(minx>x){
			        minx=x;
		        }
		    int min=a[x];
		    if(min==0){            //与上次有争端岛的右端进行比较存小的
		    	a[x]=y;
		    }else if(min>y){
		    	a[x]=y;
		    }
	    }
	    int flag=1;
	    int k=a[minx];
	    for(int i=1;i<=n;i++){
		    if(a[i]==0){
			    continue;
		    }
		    if(i>=k){        //比较岛的左端和上次争端的右端，比较；
			    flag++;
			    k=a[i];
		    }else if(k>a[i]){    //右端变小；
			    k=a[i];
		    }
	    }
	    printf("%d\n",flag);
        return 0;
}