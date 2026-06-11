/*#include<iostream>
int main(){
int a,b;
int x,y,z,count;
while(true){
std::cin>>a>>b;
count=0;
if(a==0&&b==0)break;
x=1;y=0;z=0;
for(int i=1;i<=a-2;i++){
for(int j=i+1;j<=a-1;j++){
for(int k=j+1;k<=a;k++){
if(i+j+k==b){
count++;
break;
}
}
}
}
std::cout<<count<<std::endl;
    }

    return 0;

}*/
#include<iostream>
int main(){
    int a,count=0,ans=0;
    std::cin>>a;
    for(int i=1;i<=a;i+=2){
        count=0;
        for(int j=1;j<=i;j++){
            if(i%j==0)count++;
            if(count>8)break;
        }
//        std::cout<<"i:"<<i<<" count:"<<count<<std::endl;
        if(count==8)ans++;
        
    }
    std::cout<<ans<<std::endl;
    return 0;
}
