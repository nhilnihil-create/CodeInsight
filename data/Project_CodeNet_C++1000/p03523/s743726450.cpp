#include <stdio.h>
#include <string.h>

char tar[][11] = {
    "KIHBR",
    "KIHBRA",
    "KIHBAR",
    "KIHABR",
    "AKIHBR",
    "KIHBARA",
    "KIHABRA",
    "KIHABAR",
    "AKIHBRA",
    "AKIHBAR",
    "AKIHABR",
    "KIHABARA",
    "AKIHABAR",
    "AKIHABRA",
    "AKIHBARA",
    "AKIHABARA",
    };

int main() {

    int i;
    char str[100];

    scanf("%s",str);

    for(i = 0;i < 16;i++){
        if(strcmp(tar[i],str) == 0) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}