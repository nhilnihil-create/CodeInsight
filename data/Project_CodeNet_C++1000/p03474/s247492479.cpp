#include <stdio.h>
#include <string.h>
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int size = a + b + 1;
    char name[100];
    scanf("%s", name);
    int count = 0;
    if(name[a] == '-')// untuk mengecek hypen berada di letak a + 1 tidak, jika benar lanjut ke loop
    {
        for(int i = 0; i < size; i++){
            if (name[i] >= '0' && name[i] <= '9')//mengecek angka atau bukan di dalam string
            {
                count++;
            }
        }
        if(count == a + b) // jika count = banyak angka
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
    }
    else//jika tidak print no
    {
        printf("No\n");
    }
    return 0;
}