#include<stdio.h>

#include<stdlib.h>


int main()

{

int a,b,c,d,e,f,g;

scanf("%d%d%d%d",&a,&b,&c,&d);


e=abs(a-c);
f=abs(a-b);
g=abs(b-c);
if((e<=d) || (f<=d && g<=d))

{

printf("Yes\n");

}


else

{

printf("No\n");

}

return 0;

}  