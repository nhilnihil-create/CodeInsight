#include <stdio.h>
// There is a right triangle ABC with ∠ABC = 90°. Given the lengths of the three sides, |AB|,|BC| and |CA|, find the area of the right triangle ABC. It is guaranteed that the area of the triangle ABC is an integer.
// 1 ≤ |AB|,|BC|,|CA| ≤ 100
// The area of the triangle ABC is an integer.

int main() {
    int leg1;
    int leg2;
    int hypotenuse;

    scanf("%d %d %d", &leg1, &leg2, &hypotenuse);
    printf("%d\n", leg1 * leg2 / 2);

    return 0;
}