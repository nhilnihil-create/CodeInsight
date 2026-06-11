    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<math.h>
    #include<string>
    #include<iostream>
    using namespace std;
    int times[68000000];
    char s[200000+100];
    int my_min(int a,int b)
    {
        return a<b? a:b;
    }
    int main()
    {
        scanf("%s",s);
        for(int i=0;i<68000000;i++)
            times[i]=200000+200;
        int m=0;
        times[0]=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            m=m^(1<<(s[i]-'a'));
            int p=times[m];
            for(int k=0;k<26;k++)
                p=my_min(p,times[m^(1<<k)]);
            times[m]=my_min(times[m],p+1);
      //      printf("%d\n",times[m]);
        }
        if(times[m]==0)
            printf("1");
        else
            printf("%d",times[m]);
        printf("\n");
        return 0;
    }