#include <stdio.h> 


int main() 

{

long int n,a,e; 

scanf("%ld %ld",&n,&a); 

if(n<500 && n>a)
{
printf("No\n"); 
}
else if(n>=500) 
{
e=n%500; 
if(e==0 || e<=a) 
{ 
printf("Yes\n"); 
}
else if(e>a) 
{
printf("No\n"); 
}
}
else if(n<=a)
{
printf("Yes\n"); 
} 
return 0; 
}  